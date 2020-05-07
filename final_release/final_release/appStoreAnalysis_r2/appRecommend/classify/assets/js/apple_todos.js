jQuery.get('apple_output.txt', function(data)
{
		// console.log(lines)
		var lines = data.split("\n");
		for(var i=0;i<lines.length-1;i++)
	{
		$(".first").append("<p>" + lines[i] + "<br>" + lines[i+1] + "</p>");
		i++;
	}

});
