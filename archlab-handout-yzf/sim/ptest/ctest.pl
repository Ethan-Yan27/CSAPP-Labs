#!/usr/bin/perl 
#!/usr/local/bin/perl 
# Test for pipeline hazard combinations

use Getopt::Std;
use lib ".";
use tester;

cmdline();

# Instruction templates
$tcount = 8;

@templates = 
(
 "||jne target\n\thalt\ntarget:|", # M
 "|||ret",        # R

 "||mrmovl (%eax),%esp|ret", # G1a
 "|mrmovl (%eax),%esp||ret", # G1b
 "mrmovl (%eax),%esp|||ret", # G1c
 "||irmovl \$3,%eax|rrmovl %eax,%edx", # G2a
 "|irmovl \$3,%eax||rrmovl %eax,%edx", # G2b
 "irmovl \$3,%eax|||rrmovl %eax,%edx", # G2c
);

# Try combining two templates to generate test sequence
sub make_test
{
    local ($t1, $t2) = @_;
    $ok = 1;
    @test1 = split(/\|/, $t1);
    @test2 = split(/\|/, $t2);
    for ($i = 0; $i < 4; $i++) {
	if ($test1[$i] eq "") {
	    if ($test2[$i] eq "") {
		$test[$i] = "nop";
	    } else {
		$test[$i] = $test2[$i];
	    }
	} else {
	    if ($test2[$i] eq "") {
		$test[$i] = $test1[$i];
	    } else {
		if ($test1[$i] eq $test2[$i]) {
#		    $ok = 0;
		    $test[$i] = $test1[$i];
		} else {
		    $ok = 0;
		    $test[$i] = "XXX";
		}
	    }
	}
    }
    if ($ok) {
	&gen_test($test[0], $test[1], $test[2], $test[3]);
    }

}

$testcnt = 0;

# Generate test with 4 instructions inserted
sub gen_test 
{
    local ($i1, $i2, $i3, $i4) = @_;
    $tname = "c-$testcnt";
    $testcnt++;
    open(YFILE, ">$tname.ys") || die "Can't write to $tname.ys\n";
	 
    print YFILE <<STUFF;
	irmovl Stack1,%esp
	irmovl rtnpt,%edx
	rmmovl %edx,(%esp)   # Put return point on top of Stack1
	irmovl Stack2,%eax
	rmmovl %esp,(%eax)   # Put Stack1 on top of Stack2
	irmovl Stack3,%esp   # Point to Stack3
        pushl %edx
        rrmovl %esp,%ebp
	irmovl \$3,%edx       # Initialize
	xorl   %ebx,%ebx     # Set condition codes to ZF=1,SF=0,OF=0
#       Here's where the 4 instruction sequence goes
        $i1
        $i2
        $i3
        $i4
#	Now finish things off
	irmovl \$3,%ebx       # Not reached when sequence ends with ret
	halt                  # 
rtnpt:  irmovl \$5,%esi       # Return point
	halt
.pos 0x60
	Stack1:
.pos 0x68
	Stack2:
.pos 0x70
	Stack3:
        halt
STUFF
    close YFILE;
    &run_test($tname);
}


$n = @templates;
for ($idx1 = 0; $idx1 < $n; $idx1++) {
    for ($idx2 = $idx1+1; $idx2 < $n; $idx2++) {
	&make_test($templates[$idx1],$templates[$idx2]);
    }
}

&test_stat();

