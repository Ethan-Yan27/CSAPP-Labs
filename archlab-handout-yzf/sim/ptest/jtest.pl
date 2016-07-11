#!/usr/bin/perl 
#!/usr/local/bin/perl 
# Test jump instructions

use Getopt::Std;
use lib ".";
use tester;

cmdline();

@vals = (32, 64);

@instr = ("jmp", "jle", "jl", "je", "jne", "jge", "jg", "call");

# Create set of forward tests
foreach $t (@instr) {
    foreach $va (@vals) {
	foreach $vb (@vals) {
	    $tname = "jf-$t-$va-$vb";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    print YFILE <<STUFF;
	      irmovl stack, %esp
	      irmovl \$1, %esi
	      irmovl \$2, %edi
	      irmovl \$4, %ebp
	      irmovl \$$va, %eax
	      irmovl \$$vb, %edx
	      subl %edx,%eax
	      $t target
	      addl %esi,%eax
	      addl %edi,%eax
	      addl %ebp,%eax
              halt
target:
	      addl %esi,%edx
	      addl %edi,%edx
	      addl %ebp,%edx
              nop
              nop
	      halt
.pos 0x100
stack:
STUFF
	    close YFILE;
	    &run_test($tname);
	}
    }
}

# Create set of backward tests
foreach $t (@instr) {
    foreach $va (@vals) {
	foreach $vb (@vals) {
	    $tname = "jb-$t-$va-$vb";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    print YFILE <<STUFF;
	      irmovl stack, %esp
	      irmovl \$1, %esi
	      irmovl \$2, %edi
	      irmovl \$4, %ebp
	      irmovl \$$va, %eax
	      irmovl \$$vb, %edx
	      jmp skip
	      halt
target:
	      addl %esi,%edx
	      addl %edi,%edx
	      addl %ebp,%edx
              nop
              nop
	      halt
skip:
	      subl %edx,%eax
	      $t target
	      addl %esi,%eax
	      addl %edi,%eax
	      addl %ebp,%eax
              halt
.pos 0x100
stack:
STUFF
	    close YFILE;
	    &run_test($tname);
	}
    }
}


if ($testiaddl) {
    # Create set of forward tests using iaddl
    foreach $t (@instr) {
	foreach $va (@vals) {
	    foreach $vb (@vals) {
		$tname = "ji-$t-$va-$vb";
		open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	      print YFILE <<STUFF;
	      irmovl stack, %esp
	      irmovl \$1, %esi
	      irmovl \$2, %edi
	      irmovl \$4, %ebp
	      irmovl \$$va, %eax
	      iaddl \$-$vb,%eax
	      $t target
	      addl %esi,%eax
	      addl %edi,%eax
	      addl %ebp,%eax
              halt
target:
	      addl %esi,%edx
	      addl %edi,%edx
	      addl %ebp,%edx
              nop
              nop
	      halt
.pos 0x100
stack:
STUFF
                close YFILE;
		&run_test($tname);
	    }
	}
    }
}

&test_stat();


