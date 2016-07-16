#!/usr/bin/perl 
#!/usr/local/bin/perl 
# Test single instructions in pipeline

use Getopt::Std;
use lib ".";
require tester;

cmdline();

@vals = (0x100, 0x020, 0x004);

@instr = ("rrmovl", "addl", "subl", "andl", "xorl");
@regs = ("edx", "ebx", "esp");

foreach $t (@instr) {
    foreach $ra (@regs) {
	foreach $rb (@regs) {
	    $tname = "op-$t-$ra-$rb";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    print YFILE <<STUFF;
	      irmovl \$$vals[0], %$ra
	      irmovl \$$vals[1], %$rb
	      nop
	      nop
	      nop
	      $t %$ra,%$rb
	      nop
	      nop
	      halt
STUFF
	    close YFILE;
	    run_test($tname);
	}
    }
}

if ($testiaddl) {
    foreach $ra (@regs) {
	foreach $val (@vals) {
	    $tname = "op-iaddl-$val-$ra";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    print YFILE <<STUFF;
	    irmovl \$$val, %$ra
	    nop
	    nop
	    nop
            iaddl \$-32, %$ra
	    nop
	    nop
	    halt
STUFF
            close YFILE;
	    run_test($tname);
	}
    }
}

@instr = ("pushl", "popl");
@regs = ("edx", "esp");

foreach $t (@instr) {
    foreach $ra (@regs) {
	$tname = "op-$t-$ra";
	open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	print YFILE <<STUFF;
        irmovl \$0x200,%esp
	irmovl \$$vals[1], %eax
	nop
	nop
        nop
        rmmovl %eax, 0(%esp)
	irmovl \$$vals[2], %eax
	nop
        nop
        nop
	rmmovl %eax, -4(%esp)
	irmovl \$$vals[0], %edx
	nop
        nop
        nop
	$t %$ra
	nop
	nop
        halt
STUFF
	close YFILE;
	&run_test($tname);
    }
}

if ($testleave) {
    $tname = "op-leave";
    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
    print YFILE <<STUFF;
    irmovl \$0x100,%ebp
    irmovl \$0x123,%eax
    irmovl \$0xabc,%edx
    nop
    nop
    rmmovl %eax, 0(%ebp)
    rmmovl %edx, -4(%ebp)
    nop
    nop
    nop
    leave
    nop
    nop
    halt
STUFF
    close YFILE;
    &run_test($tname);
}

&test_stat();
