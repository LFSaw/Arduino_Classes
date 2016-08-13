#!/usr/bin/env python

##@file mozzify.py
# Simple script to make char2mozzi.py a little easier to use.
#	char2mozzi.py -> A script for converting raw 8 bit sound data files to wavetables for Mozzi.
#
#	Usage:
#	>>>mozzify.py infile outfile tablename samplerate
#
#	@param infile		The file to convert, RAW(headerless) Signed 8 bit PCM.
#	@param outfile	The file to save as output, a .h file containing a table for Mozzi.
#	@param tablename	The name to give the table of converted data in the new file.
#	@param samplerate	The samplerate the sound was recorded at.  Choose what make sense for you, if it's not a normal recorded sample.
#
#	@note Using Audacity to prepare raw sound files for converting:
#
#	For generated waveforms like sine or sawtooth, set the project
#	rate to the size of the wavetable you wish to create, which must
#	be a power of two (eg. 8192), and set the selection format
#	(beneath the editing window) to samples. Then you can generate
#	and save 1 second of a waveform and it will fit your table
#	length.
#
#	For a recorded audio sample, set the project rate to the
#	Mozzi AUDIO_RATE (16384 in the current version).
#	Samples can be any length, as long as they fit in your Arduino.
#
#	Save by exporting with the format set to "Other uncompressed formats",
#	"Header: RAW(headerless)" and "Encoding: Signed 8 bit PCM".
#
#	Now use the file you just exported, as the "infile" to convert.
#
#	@author Tim Barrass 2010-12
#	@fn char2mozzi
from __future__ import print_function
import sys, array, os, textwrap, random
from char2mozzi import char2mozzi


if len(sys.argv) != 5:
    print('Usage: mozzify infile outfile tablename samplerate')
    sys.exit(1)
[infile, outfile, tablename, samplerate] = sys.argv[1:]
outfile = os.path.join("/Volumes/Store/Box Sync/_PROJECTS/Arduino_Classes/samples/", outfile)
char2mozzi(infile, outfile, tablename, samplerate)
