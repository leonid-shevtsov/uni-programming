#!/usr/bin/perl

use strict;
use warnings;
use CGI;

my $cgi = CGI->new();

print $cgi->header('text/plain');

print "Form method: $ENV{'REQUEST_METHOD'}\n\n";
print "# Form parameters #\n";
my $keywords = $cgi->param;
foreach($cgi->param) {
  my $value = $cgi->param($_);
  print  "$_: \"$value\"\n";
}

