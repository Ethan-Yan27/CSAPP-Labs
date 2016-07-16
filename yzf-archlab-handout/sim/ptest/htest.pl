#!/usr/bin/perl 
#!/usr/local/bin/perl 
# Test for pipeline hazards

use Getopt::Std;
use lib ".";
use tester;

cmdline();

# Destination Instructions
@dest =
(
 # Having %eax as destination
 "1:rrmovl %ecx,%eax",
 "1:irmovl \$0x101,%eax",
 "1:mrmovl 0(%ebp),%eax",
 "1:addl   %eax,%eax",
 "1:popl   %eax",
 "1:cmovne %ecx,%eax", # Not taken
 "1:cmove  %ecx,%eax", # Taken
 # Instructions having %ebp as destination
 "2:rrmovl %eax,%ebp",
 "2:irmovl \$0x100,%ebp",
 "2:mrmovl 4(%ebp),%ebp",
 "2:addl   %eax,%ebp",
 "2:popl   %ebp",
 "2:cmovne %eax,%ebp", # Not taken
 "2:cmove  %eax,%ebp", # Taken
 # Instructions having %esp as destination
 "3:rrmovl %ebp,%esp",
 "3:irmovl \$0x104,%esp",
 "3:mrmovl 4(%ebp),%esp",
 "3:addl   %eax,%esp",
 "3:popl   %ebp",
 "3:pushl  %eax",
 "3:pushl  %esp",
 "3:popl   %esp",
 "1:cmovne %ebp,%esp", # Not taken
 "1:cmove  %ebp,%esp"  # Taken
 );

if ($testiaddl) {
    @dest = (@dest,
	     "1:iaddl \$0x201,%eax",
	     "2:iaddl \$0x4,%ebp",
	     "3:iaddl \$0x4,%esp",);
}

if ($testleave) {
    @dest = (@dest,  "2:leave", "3:leave");
}

@src = 
(
 # Instructions having %eax as source
 "1:rrmovl %eax,%ebp",
 "1:rmmovl %eax,0(%ebp)",
 "1:rmmovl %ebp,0(%eax)",
 "1:mrmovl 4(%eax),%ebp",
 "1:addl   %eax,%ebp",
 "1:addl   %ebp,%eax",
 "1:addl   %eax,%eax",
 "1:pushl  %eax",
 # Instructions having %ebp as source
 "2:rrmovl %ebp,%ebp",
 "2:rmmovl %ebp,4(%ebp)",
 "2:rmmovl %eax,0(%ebp)",
 "2:mrmovl 8(%ebp),%eax",
 "2:addl   %ebp,%eax",
 "2:addl   %eax,%ebp",
 "2:addl   %ebp,%ebp",
 "2:pushl  %ebp",
 # Instructions having %esp as source
 "3:rrmovl %esp,%ebp",
 "3:rmmovl %esp,4(%ebp)",
 "3:rmmovl %eax,-4(%esp)",
 "3:mrmovl 4(%esp),%eax",
 "3:addl   %esp,%eax",
 "3:addl   %eax,%esp",
 "3:addl   %esp,%esp",
 "3:pushl  %esp",
 "3:ret"
 );

if ($testiaddl) {
    @src = (@src,
	    "1:iaddl \$0x301,%eax",
	    "2:iaddl \$0x8,%ebp",
	    "3:iaddl \$0x8,%esp");
}

if ($testleave) {
    @src = (@src,  "2:leave", "3:leave");
}

# Generate test with 4 instructions inserted
sub gen_test 
{
    local ($i1, $i2, $i3, $i4) = @_;
    print YFILE <<STUFF;
    # Preamble.  Initialize memory and registers
    irmovl \$0xf5,%eax
    irmovl \$0,%ebp
    rmmovl %eax,0xf0(%ebp)
    irmovl \$0xf7,%eax
    rmmovl %eax,0xf4(%ebp)
    irmovl \$0xfb,%eax
    rmmovl %eax,0xf8(%ebp)
    irmovl \$0xff,%eax
    rmmovl %eax,0xfc(%ebp)
    irmovl \$0x100,%ebp
    irmovl \$0x10c,%esp
    xorl %eax,%eax      # Set Z condition code
    irmovl \$0x80,%eax
    # Test 4 instruction sequence
    $i1
    $i2
    $i3
    $i4
    # Put in another instruction
    rrmovl %esp,%ebp
    # Complete
    halt

.pos 0x08
     .long pos01
     .long pos02
     .long pos03
     .long pos04
     .long pos05
     .long pos06
pos01:
     halt
pos02:
     halt
pos03:
     halt
pos04:
     halt
pos05:
     halt
pos06:
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt
     halt

.pos 0x100
    .long pos11
    .long pos12
    .long pos13
    .long pos14
    .long pos15
    .long pos16
pos11:
    halt
pos12:
    halt
pos13:
    halt
pos14:
    halt
pos15:
    halt
pos16:
    halt
    halt
    halt
    halt
    halt
    halt
    halt
    halt
    halt

.pos 0x180
    .long pos21
    .long pos22
    .long pos23
    .long pos24
    .long pos25
    .long pos26
pos21:
    halt
pos22:
    halt
pos23:
    halt
pos24:
    halt
pos25:
    halt
pos26:
    halt
    halt
    halt
    halt
    halt
    halt
    halt
    halt
    halt
STUFF
}

# Generate pairwise tests
$di = 0;
$si = 0;
foreach $dline (@dest) {
    foreach $sline (@src) {
	($dtype, $d) = split /:/, $dline;
	($stype, $s) = split /:/, $sline;
	if ($dtype == $stype) {
	    # Two instructions with 2 nops between them
	    $tname = "hnn-$di-$si";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    &gen_test($d, "nop", "nop", $s);
	    close  YFILE;
	    &run_test($tname);

	    # Two instructions with nop between them
	    $tname = "hn-$di-$si";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    &gen_test($d, "nop", "", $s);
	    close  YFILE;
	    &run_test($tname);

	    # Two instructions in succession
	    $tname = "h-$di-$si";
	    open (YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	    &gen_test($d, "", "", $s);
	    close  YFILE;
	    &run_test($tname);
	}
	$si++;
    }
    $si = 0;
    $di++;
}

&test_stat();
