#!/usr/bin/env python

from os import listdir
import subprocess
exec_path = 'exe/zadanie2.exe'
#exec_path = 'exe/diff.exe'
in_dir = 'in/'
out_dir = 'out/'
log_path = 'log.txt';

fnames = listdir(in_dir)
fnames_amt = len(fnames)
if(fnames_amt%2!=0):
	print 'Last test from "in" dir will be ommited.\n'
	print 'There is uneven number of files.\n'
	fnames_amt-=1
tests_amt = fnames_amt//2

for i in range(1,tests_amt*2,2):
	print '====================TEST START================='
	fname1 = fnames[i-1]
	fname2 = fnames[i]
	print 'Tested files:' + fname1 +', ' + fname2
	proc = subprocess.Popen([exec_path,in_dir+fname1,in_dir+fname2],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
	output = proc.stdout.read()
	errors = proc.stderr.read()
	print 'Output:'
	print output
	if(len(errors)>0):
		print 'Errors:'
		print errors
	print '====================TEST END==================='
	
	
	


	
