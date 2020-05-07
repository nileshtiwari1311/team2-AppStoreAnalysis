var gplay = require('google-play-scraper');
const args = process.argv;

function ret_category()
{
	if(args[3] == 'edu')
	{
		return gplay.category.EDUCATION;
	}
	if(args[3] == 'ent')
	{
		return gplay.category.ENTERTAINMENT;
	}
	if(args[3] == 'foo')
	{
		return gplay.category.FOOD_AND_DRINK;
	}
	if(args[3] == 'lif')
	{
		return gplay.category.LIFESTYLE;
	}
	if(args[3] == 'map')
	{
		return gplay.category.MAPS_AND_NAVIGATION;
	}
	if(args[3] == 'mus')
	{
		return gplay.category.MUSIC_AND_AUDIO;
	}
	if(args[3] == 'new')
	{
		return gplay.category.NEWS_AND_MAGAZINES;
	}
	if(args[3] == 'pho')
	{
		return gplay.category.PHOTOGRAPHY;
	}
	if(args[3] == 'pro')
	{
		return gplay.category.PRODUCTIVITY;
	}
	if(args[3] == 'sho')
	{
		return gplay.category.SHOPPING;
	}
	if(args[3] == 'soc')
	{
		return gplay.category.SOCIAL;
	}
	if(args[3] == 'too')
	{
		return gplay.category.TOOLS;
	}
	if(args[3] == 'tra')
	{
		return gplay.category.TRAVEL_AND_LOCAL;
	}
	if(args[3] == 'gam')
	{
		return gplay.category.GAME;
	}
}

function ret_collection()
{
	if(args[4] == 'free')
	{
		return gplay.collection.TOP_FREE;
	}
	if(args[4] == 'paid')
	{
		return gplay.collection.TOP_PAID;
	}
}

gplay.list({
	num: 10,
    category: ret_category(),
    collection: ret_collection(),
    country: args[2],
    fullDetail: true
  })
  .then(console.log)
  .catch(console.log);