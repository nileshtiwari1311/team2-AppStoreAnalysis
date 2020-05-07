var header="https://play.google.com/store/apps/details?id=";
var header1="https://apps.apple.com/in/app/id";

jQuery.get('single_app_details.txt', function(data)
{
		
		var lines = data.split("\n");
		var labels = new Array(10) ;
		labels[0] = "Title : ";
		labels[1] = "Score : ";
		labels[2] = "No. of Reviews : ";
		labels[3] = "Price : ";
		labels[4] = "Size : ";
		labels[5] = "AndroidVersionText : ";
		labels[6] = "Developer : ";
		labels[7] = "First released : ";
		labels[8] = "Last Updated : ";
		labels[9] = "Link : ";
		
		// console.log(lines);
		for(var i=0;i<lines.length-1;i++)
		{
			$(".first").append("<p>"+ "<u>" + labels[i] + "</u>" + lines[i] + "</p>");
		}

});


jQuery.get('single_app_details_2.txt', function(data)
{
		
		var lines = data.split("\n");
		// console.log(lines);
		var labels = new Array(10) ;
		labels[0] = "Title : ";
		labels[1] = "Score : ";
		labels[2] = "No. of Reviews : ";
		labels[3] = "Price : ";
		labels[4] = "Size : ";
		labels[5] = "OsVersionRequired : ";
		labels[6] = "Developer : ";
		labels[7] = "First released : ";
		labels[8] = "Last Updated : ";
		labels[9] = "Link : ";
		
		// console.log(lines);
		for(var i=0;i<lines.length-1;i++)
		{
			$(".second").append("<p>"+ "<u>" + labels[i] + "</u>" + lines[i] + "</p>");
		}	
		
});