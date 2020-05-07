var header="https://play.google.com/store/apps/details?id=";
var header1="https://apps.apple.com/in/app/id";
var cl_header = "/appStoreAnalysis_r2/appRecommend/classify/google_classifier.php?id=";
var cl_header1 = "/appStoreAnalysis_r2/appRecommend/classify/apple_classifier.php?id=";

jQuery.get('output.txt', function(data)
{
		
		var lines = data.split("\n");
		// console.log(lines);
		for(var i=0;i<lines.length-1;i++)
	{
		$(".first").append("<p>" + "<a href="+header+lines[i]+">"+ lines[i] + "</a>"+ "<a href="+cl_header+lines[i]+" target='_blank'>"+  "<img src='assets/images/up-arrow.png' alt='Classify reviews' height=10 width=10>" + "</a>"+"</p>");
	}

});


jQuery.get('output_2.txt', function(data)
{
		
		var lines = data.split("\n");
		// console.log(lines);
		for(var i=0;i<lines.length-1;i++)
	{
		$(".second").append("<p>" + "<a href="+header1+lines[i]+">"+ lines[i] + "</a>"+ "<a href="+cl_header1+lines[i]+" target='_blank'>"+  "<img src='assets/images/up-arrow.png' alt='Classify reviews' height=10 width=10>" + "</a>"+"</p>");
	}	
		
});
