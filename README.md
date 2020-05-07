# Team_2_AppStoreAnalysis
Software Engineering Lab Tool
This is a tool to analyze the behaviour of a particular app on multiple app stores, to show the top apps available within a category on a particular app store based on the metrics directly provided by the app store or the ones developed by us based on the metadata provided by the app store and to classify the recent reviews of apps into 4 categories: feature requests, bug reports, user experience and ratings . 
Factors that are taken into account for doing it are number of downloads, rating, price, country, released date, last updated date, recent reviews and recent ratings. 
The scraping and classification of reviews into 4 categories helps the user understand what are the issues going on with the app in recent time through bug reports, what features people want in the app through feature requests, and what are the user experiences.

Usage:
1. It is a server side application which requires Xampp Apache server, Python 3.7, g++ and Nodejs.
2. It uses nodejs modules : app-store-scraper, google-play-scraper, cheerio, debug, memoizee, eslint, xml2js, request, ramda and throttled-request.
3. Place the folder appStoreAnalysis_r2 in Xampp's htdocs folder.
4. Make sure you have nodejs modules installed inside the Xampp folder.
