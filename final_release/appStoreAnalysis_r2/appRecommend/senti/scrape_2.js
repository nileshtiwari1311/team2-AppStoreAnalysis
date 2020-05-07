var store = require('app-store-scraper');

const args = process.argv;

function ret_category()
{
	if(args[3] == 'edu')
	{
		return store.category.EDUCATION;
	}
	if(args[3] == 'ent')
	{
		return store.category.ENTERTAINMENT;
	}
	if(args[3] == 'foo')
	{
		return store.category.FOOD_AND_DRINK;
	}
	if(args[3] == 'lif')
	{
		return store.category.LIFESTYLE;
	}
	if(args[3] == 'map')
	{
		return store.category.NAVIGATION;
	}
	if(args[3] == 'mus')
	{
		return store.category.MUSIC;
	}
	if(args[3] == 'new')
	{
		return store.category.NEWS;
	}
	if(args[3] == 'pho')
	{
		return store.category.PHOTO_AND_VIDEO;
	}
	if(args[3] == 'pro')
	{
		return store.category.PRODUCTIVITY;
	}
	if(args[3] == 'sho')
	{
		return store.category.SHOPPING;
	}
	if(args[3] == 'soc')
	{
		return store.category.SOCIAL_NETWORKING;
	}
	if(args[3] == 'too')
	{
		return store.category.UTILITIES;
	}
	if(args[3] == 'tra')
	{
		return store.category.TRAVEL;
	}
	if(args[3] == 'gam')
	{
		return store.category.GAMES;
	}
}

function ret_collection()
{
	if(args[4] == 'free')
	{
		return store.collection.TOP_FREE_IOS;
	}
	if(args[4] == 'paid')
	{
		return store.collection.TOP_PAID_IOS;
	}
}


store.list({
	collection: ret_collection(),
	category: ret_category(),
	country: args[2],
	num: 10,
	fullDetail: true
})
.then(console.log)
.catch(console.log);