from PIL import Image
import sys
import code



im = Image.open("chicago.bmp") #Can be many different formats.
pix = im.load()
print im.size #Get the width and hight of the image for iterating over
print pix[0,0] #Get the RGBA Value of the a pixel of an image


chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ?:"


# find start markers should be 1 px away from first char.
# red marker denotes bit 1
# blue marker denotes bit 16
# charecters are seperated by 2 pixels of blank space
# bits to set are white and blank bits are black.

start = 0;
end = 0;
line = 0;
blankcnt = 0;
letter = 0;
for x in range(0,im.size[0]):
	for y in range(0,im.size[1]):
		if pix[x,y] !=0:
			if pix[x,y] == 14:
#				print "Start is (x:%s,y:%s)" % (x,y)
				start = y
				line = x
			if pix[x,y] == 1:
#				print "End is is (x:%s,y:%s)" % (x,y)
				end = y
#				print end
#			print "%s,%s [%s]" % (x,y,pix[x,y])

print "%d,%d,%d" %  (start,end,line)
#exit()
# build array


# assemble an array of pixel colums
fheight = end-start;
words = []
for x in range(0,im.size[0]-line):
	word = 0
	for y in range(fheight,-1,-1):
		if pix[x+line,y+start] == 63:
			word = word | (1<<y)
	words.append(word)

# break up into letters
letters = []
letter = []
blankcnt = 0
for word in words:
	letter.append(word)
#	print word
	if word==0:
		blankcnt +=1
	
	# 2 blanks in a row. new letter
	if blankcnt>1:
#		print "new letter"
		blankcnt=0
		letters.append(letter)
		letter = []

# prune empty letters
letterspruned = []
for letter in letters:
	if letter == [0,0]:
		pass
#		print "null removed"
	else:
		letterspruned.append(letter)


print "// Got %d letters" % (len(letterspruned))
#print letterspruned

# assemble letters into dict
lettersdict = []
idx = 0
offset = 0

for letter in letterspruned:
#	print "Pos: %d Len: %d" % (idx,len(letter)-2)
	ub = []
	lb = []
	for line in letter[0:-2]:
		ub.append(line>>8)
		lb.append(line & 0xff)
		
	lettersdict.append({'upperb': ub, 'lowerb': lb, 'len': len(letter)-2 , 'char': chars[idx], 'off': offset} )
	idx += 1
	offset += len(ub)
	
	
# calculate byte usage
# the offset/len table. 2 bytes for each letter. 0-127
bytes = 256
for letter in lettersdict:
	for line in letter['upperb']:
		bytes +=2 # 2 bytes for each line



#for letter in lettersdict:
#	print "\n"+str(letter)		
	
#build c array

#build offsets array. ascii layout

offascii = []
for idx in range(0,127):
	#serch array for char
	char = ''
	for letter in lettersdict:
		if ord(letter['char']) == idx:
			char = letter
	if char == '':
		offascii.append([])
	else:
		offascii.append(char)		
	
# font offset and length table
idx = 0
wrap = 0;
print """
// Font Offset and Lenth table
//
//   first nibble is char length
//   upper 3 nibbles are offet into font array
//
//   layout is ASCII. index into this font_off_len_table[asciicode]
//   Chars of 0x0000 have no char.

"""
print "uint_16_t font_off_len_table[] = {",
for o in offascii:
	if o != []:
		print "0x%03x%01x" % (o['off'],o['len']),
	else:
		print "0x0000",
		
	if idx<127:
		sys.stdout.write(','),
	else:
		sys.stdout.write('};'),	
	idx +=1
	wrap  += 1
	if wrap>7:
		print ""
		wrap=0

print """
// Upper Byte Char Data Array
//   chars are max 16 pix high
//   broken into two strips
//   this strip is the top 8 pixels

"""

print "uint8_t font_upper_pix[] = {"
for letter in lettersdict:
#	print "\n// %s\n" % letter['char'], #newline after every char
	print ""
	for line in letter['upperb']:
		print "0x%02x," % (line),
print "\b\b};"
	
print """
// Lower Byte Char Data Array
//   chars are max 16 pix high
//   broken into two strips
//   this strip is the top 8 pixels

"""

print "uint8_t font_lower_pix[] = {"
for letter in lettersdict:
#	print "\n// %s\n" % letter['char'], #newline after every char
	print ""
	for line in letter['lowerb']:
		print "0x%02x," % (line),
print "\b\b};"

		
print "\n\n//Font uses %d bytes" % bytes		


#off = 0
#idx = 0
#for letter in lettersdict:
#	print "['%d,%d,'%s']," % (off,letter['len'],chars[idx])
#	for b in letter['upperb']:
#		off += 1
#	idx += 1
#build lower array
#build upper array

#for letter in lettersdict:
#	print "[%02x,%02x],\t// %s" % (letter.upperb, letter.lowerb, )


#code.interact(local=locals())

#pix[x,y] = value # Set the RGBA Value of the image (tuple)