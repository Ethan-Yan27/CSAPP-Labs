#!/usr/bin/perl 
#!/usr/local/bin/perl 

#
# gen-driver - Generate driver file for any ncopy function
#
use Getopt::Std;

$n = 0;

getopts('hcrn:f:b:');

if ($opt_h) {
    print STDERR "Usage $argv[0] [-h] [-c] [-n N] [-f FILE]\n";
    print STDERR "   -h      print help message\n";
    print STDERR "   -c      include correctness checking code\n";
    print STDERR "   -n N    set number of elements\n";
    print STDERR "   -f FILE set input file (default stdin)\n";
    print STDERR "   -b blim set byte limit for function\n";
    print STDERR "   -r      Allow random result\n";
    die "\n";
}

$check = 0;
if ($opt_c) {
    $check = 1;
}

$bytelim = 1000;
if ($opt_b) {
    $bytelim = $opt_b;
}

if ($opt_n) {
    $n = $opt_n;
    if ($n < 0) {
	print STDERR "n must be at least 0\n";
	die "\n";
    }
}

$randomval = 0;
# Accumulated count
$rval = 0;

if ($opt_r) {
  $randomval = 1;
} else {
  # Value that should be returned by function
  $tval = int($n/2);
}


# The data to be stored.
@data = ();

for ($i = 0; $i < $n; $i++) {
  $data[$i] = -($i+1);
  if ($randomval) {
    if (int(rand(2)) == 1) {
      $data[$i] = -$data[$i];
      $rval++;
    }
  } else {
    if ($rval < $tval && int(rand(2)) % 2 == 1 ||
	$tval - $rval >= $n - $i) {
      $data[$i] = -$data[$i];
      $rval++;
    }
  }
}


# Values to put at beginning and end of destination
$Preval =  "0xbcdefa";
$Postval = "0xdefabc";


print <<PROLOGUE;
#######################################################################
# Test for copying block of size $n;
#######################################################################
	.pos 0
main:	irmovl Stack, %esp  	# Set up stack pointer
	irmovl Stack, %ebp  	# Set up base pointer

	# Set up arguments for copy function and then invoke it
	irmovl \$$n, %eax		# src and dst have $n elements
	pushl %eax
	irmovl dest, %eax	# dst array
	pushl %eax
	irmovl src, %eax	# src array
	pushl %eax
	call ncopy		 
PROLOGUE

if ($check) {
print <<CALL;
	call check	        # Call checker code
	halt                    # should halt with 0xaaaa in %eax
CALL
} else {
print <<HALT;
	halt			# should halt with num nonzeros in %eax
HALT
}

print "StartFun:\n";
if ($opt_f) {
    open (CODEFILE, "$opt_f") || die "Can't open code file $opt_f\n";
    while (<CODEFILE>) {
	printf "%s", $_;
    }
} else {
    while (<>) {
	printf "%s", $_;
    }
}
print "EndFun:\n";

if ($check) {
print <<CHECK;
#################################################################### 
# Epilogue code for the correctness testing driver
####################################################################

# This is the correctness checking code.
# It checks:
#   1. %eax has $rval.  Set %eax to 0xbbbb if not.
#   2. The total length of the code is less than or equal to $bytelim.
#      Set %eax to 0xcccc if not.
#   3. The source data was copied to the destination.
#      Set %eax to 0xdddd if not.
#   4. The words just before and just after the destination region
#      were not corrupted.  Set %eax to 0xeeee if not.
# If all checks pass, then sets %eax to 0xaaaa
check:
	pushl %ebp
	rrmovl %esp,%ebp
	pushl %esi
	pushl %ebx
	pushl %edi
	# Return value test
	irmovl \$$rval,%edx
	subl %edx,%eax
	je checkb
	irmovl \$0xbbbb,%eax  # Failed test #1
	jmp cdone
checkb:
	# Code length check
	irmovl EndFun,%eax
	irmovl StartFun,%edx
	subl %edx,%eax
	irmovl \$$bytelim,%edx
	subl %eax,%edx
	jge checkm
	irmovl \$0xcccc,%eax  # Failed test #2
	jmp cdone
checkm:
	irmovl dest, %edx # Pointer to next destination location
	irmovl src,%ebx   # Pointer to next source location
	irmovl \$$n,%edi  # Count
	andl %edi,%edi
	je checkpre         # Skip check if count = 0
mcloop:
	mrmovl (%edx),%eax
	mrmovl (%ebx),%esi
	subl %esi,%eax
	je  mok
	irmovl \$0xdddd,%eax # Failed test #3
	jmp cdone
mok:
	irmovl \$4,%eax
	addl %eax,%edx	  # dest ++
	addl %eax,%ebx    # src++
	irmovl \$1,%eax
	subl %eax,%edi    # cnt--
	jg mcloop
checkpre:
	# Check for corruption
	irmovl Predest,%edx
	mrmovl (%edx), %eax  # Get word before destination
	irmovl \$$Preval, %edx
	subl %edx,%eax
	je checkpost
	irmovl \$0xeeee,%eax  # Failed test #4
	jmp cdone
checkpost:
	# Check for corruption
	irmovl Postdest,%edx
	mrmovl (%edx), %eax  # Get word after destination
	irmovl \$$Postval, %edx
	subl %edx,%eax
	je checkok
	irmovl \$0xeeee,%eax # Failed test #4
	jmp cdone
checkok:
	# Successful checks
	irmovl \$0xaaaa,%eax
cdone:
	popl %edi
	popl %ebx
	popl %esi
	rrmovl %ebp, %esp
	popl %ebp
	ret
CHECK
}

print <<EPILOGUE1;

###############################
# Source and destination blocks 
###############################
	.align 4
src:
EPILOGUE1

for ($i = 0; $i < $n; $i++) {
    print "\t.long $data[$i]\n";
}

print <<EPILOGUE2;
	.long $Preval # This shouldn't get moved

	.align 16
Predest:
	.long $Preval
dest:
EPILOGUE2

for ($i = 0; $i < $n; $i++) {
    print "\t.long 0xcdefab\n";
}

print <<EPILOGUE3;
Postdest:
	.long $Postval

.align 4
# Run time stack
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0

Stack:
EPILOGUE3

