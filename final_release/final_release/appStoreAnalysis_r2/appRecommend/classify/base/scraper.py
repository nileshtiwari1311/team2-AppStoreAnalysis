from selenium import webdriver
from time import sleep
from bs4 import BeautifulSoup, Comment
import pandas as pd
import csv
import subprocess
import shlex
from selenium.webdriver.firefox.firefox_binary import FirefoxBinary

def scrape_all_reviews(Name, ID1, serial_no):
	print(Name, ID1)
	l1 = "https://play.google.com/store/apps/details?id="
	id_1 = l1+ID1
	link = id_1+"&hl=en&showAllReviews=true"
	print("Final URL: ", link)

	# binary = FirefoxBinary('path/to/installed firefox binary')
	# driver = webdriver.Firefox(firefox_binary=binary)
	driver = webdriver.Firefox()
	driver.get(link)

	Ptitle = driver.find_element_by_css_selector('.AHFaub span').text
	print(Ptitle)

	sleep(1)

	lenOfPage = driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
	match=False
	while(match==False):
		lastCount = lenOfPage
		sleep(1)
		lenOfPage = driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
		if lastCount==lenOfPage:
			try:
				n = 20
				driver.find_element_by_xpath("//span[@class='RveJvd snByac']").click()
				while(n>0):
					n = n -1
					lastCount = lenOfPage
					sleep(2)
					lenOfPage = driver.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
					if(lenOfPage==lastCount):
						driver.find_element_by_xpath("//span[@class='RveJvd snByac']").click()
			except NameError: 
				print("here3")
		else:
				match=True

	Name = []
	Review = []
	upvotes = []
	rating = []
	date = []

	people = driver.find_elements_by_xpath('//span[@class="X43Kjb"]')
	for person in people:
		name = person.text
		Name.append(name)

	count = 1
	reviews = driver.find_elements_by_xpath('//span[@jsname="bN97Pc"]')
	for review in reviews:
		rev = review.text
		Review.append(rev)

	dates = driver.find_elements_by_xpath('//span[@class="p2TkOb"]')
	for d in dates:
		d1 = d.text
		date.append(d1)

	stars = driver.find_elements_by_xpath('//div[@class="pf5lIe"]/div')
	for s in stars:
		s1 = s.get_attribute('aria-label')
		rating.append(s1)

	thumps_up = driver.find_elements_by_xpath('//div[@class="jUL89d y92BAb"]')
	for t in thumps_up:
		t1 = t.text
		upvotes.append(t1)

	a = []
	a.append(Name)
	a.append(Review)
	a.append(upvotes)
	a.append(rating)
	a.append(date)

	with open("test"+str(serial_no)+".csv", "w", encoding = 'utf-8') as f:
	    writer = csv.writer(f)
	    writer.writerows(a)

scrape_all_reviews("Google Classroom", "com.google.android.apps.classroom",1)
scrape_all_reviews("BYJU'S – The Learning App", "com.byjus.thelearningapp",2)
scrape_all_reviews("UVideo - Share Videos, Status Downloader, Shayari", "com.kwai.global.video.social.kwaigo",3)
scrape_all_reviews("Amazon Prime Video", "com.amazon.avod.thirdpartyclient",4)
scrape_all_reviews("Swiggy Food Order & Delivery", "in.swiggy.android",5)
scrape_all_reviews("Zomato - Restaurant Finder and Food Delivery App", "com.application.zomato",6)
scrape_all_reviews("Horoscopes – Daily Zodiac Horoscope & Astrology", "ru.mail.horo.android",7)
scrape_all_reviews("Pinterest", "com.pinterest",8)
scrape_all_reviews("Vehicle Owner Details", "com.cuvora.carinfo",9)
scrape_all_reviews("Ola. Get rides on-demand", "com.olacabs.customer",10)
scrape_all_reviews("Gaana Music Hindi Tamil Telugu MP3 Songs Video App", "com.gaana",11)
scrape_all_reviews("Wynk Music - Download & Play Songs, MP3, HelloTune", "com.bsbportal.music",12)
scrape_all_reviews("Public - Local Videos", "com.cardfeed.video_public",13)
scrape_all_reviews("Aaj Tak Live TV News - Latest Hindi India News App", "in.AajTak.headlines",14)
scrape_all_reviews("BeautyPlus - Easy Photo Editor & Selfie Camera", "com.commsource.beautyplus",15)
scrape_all_reviews("PicsArt Photo Editor: Pic, Video & Collage Maker", "com.picsart.studio",16)
scrape_all_reviews("Paytm - BHIM UPI, Money Transfer & Mobile Recharge", "net.one97.paytm",17)
scrape_all_reviews("Flipkart Online Shopping App", "com.flipkart.android",18)
scrape_all_reviews("TikTok", "com.zhiliaoapp.musically",19)
scrape_all_reviews("Instagram", "com.instagram.android",20)
scrape_all_reviews("Triplens: Photo Translator", "com.triplens.android",21)
scrape_all_reviews("SHAREit - Transfer & Share", "com.lenovo.anyshare.gps",22)
scrape_all_reviews("Maps - Navigate & Explore", "com.google.android.apps.maps",23)
scrape_all_reviews("Where is my Train : Indian Railway Train Status", "com.whereismytrain.android",24)
scrape_all_reviews("Ludo King", "com.ludo.king",25)
scrape_all_reviews("PUBG MOBILE", "com.tencent.ig",26)
scrape_all_reviews("MyJio: For Everything Jio", "com.jio.myjio",27)
scrape_all_reviews("CamScanner - Scanner to scan PD", "com.intsig.camscanner",28)