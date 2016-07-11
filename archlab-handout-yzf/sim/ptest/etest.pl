#!/usr/bin/perl 
#!/usr/local/bin/perl 
# Test for exception followed by state-setting instruction

use Getopt::Std;
use lib ".";
use tester;

cmdline();

# State setting instructions
@stateset =
(
 # Set condition codes
 "andl %ecx,%ecx",
 # Write to memory
 "rmmovl %ecx,(%eax)"
);

# Exception causing instructions
@exceptset = 
(
 # halt
 "halt",
 # Invalid instruction
 ".byte 0xFF",
 # Invalid write address
 "rmmovl %eax,0xF0000000(%eax)"
);

# Generate test with 3 instructions inserted
sub gen_test 
{
    local ($i1, $i2, $i3) = @_;
    print YFILE <<STUFF;
    # Preamble.  Initialize memory and registers
    irmovl \$-1,%ecx    # Create nonzero value
    irmovl \$0x100,%eax
    xorl %edx,%edx      # Set Z condition code
    # Test 3 instruction sequence
    $i1
    $i2
    $i3
    # Complete
    nop
    nop
    halt
STUFF
}

# Generate pairwise tests
$ei = 0;
$si = 0;
foreach $e (@exceptset) {
    foreach $s (@stateset) {
        # Two instructions with 1 nop between them
	$tname = "en-$ei-$si";
	open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	&gen_test($e, "nop", $s);
	close  YFILE;
	&run_test($tname);

	# Two instructions in succession
	$tname = "e-$ei-$si";
	open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	&gen_test($e, "", $s);
	close  YFILE;
	&run_test($tname);
	$si++;
      }
    $si = 0;
    $ei++;
}

&test_stat();
