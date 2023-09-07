use strict;
use warnings;

sub rec {
    my ($NumberOfRowsLeft) = @_;
    if ($NumberOfRowsLeft == 1) {
        my @array = (1);
        print "[1]\n";
        return @array;
    }
    my @LastCall = rec($NumberOfRowsLeft - 1);
    my @CurrentCall = ();
    $CurrentCall[0] = $LastCall[$#LastCall];
    for my $currentRow (0..$NumberOfRowsLeft - 2) {
        $CurrentCall[$currentRow + 1] = $CurrentCall[$currentRow] + $LastCall[$currentRow];
    }
    print "[";
    for my $i (0..$#CurrentCall) {
        print $CurrentCall[$i];
        if ($i != $#CurrentCall) {
            print ", ";
        }
    }
    print "]\n";
    return @CurrentCall;
}

my $numberOfRows = 7;
print "Aitken's array of $numberOfRows:\n\n";
rec($numberOfRows);