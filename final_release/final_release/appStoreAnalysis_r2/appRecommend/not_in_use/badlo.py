import re
f = open("output_details.txt", "r",  encoding="utf8")
nilu = open("kaali.json","w+",  encoding="utf8")

contents = f.read()

l = ['title:', 'appId:', 'url:', 'icon:', 'developer:', 'developerId:', 'priceText:', 'currency:', 'price:', 'free:', 'summary:', 'scoreText:', 'score:']
x = [w for w in contents.split() if w.endswith(":")]

for i in x:
	print(i)
	if not (i in l):
		contents = contents.replace(i, i[:len(i)-1])

contents = contents.replace('"', '')
contents = contents.replace('\'','"')

x = [w for w in contents.split() if w.endswith(":")]
for i in x:
	# print(i)
	if i[len(i)-2]!='"' :
		p = '"'+ i[:len(i)-1] + '"' + ':'
		# print(p)
		contents = contents.replace(i, p)

un = "undefined"
contents = contents.replace(un, '"NA"')


print(contents)

nilu.write(contents)
nilu.close()