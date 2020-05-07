<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO"
        crossorigin="anonymous">
	<title>Apps</title>
	<link rel="stylesheet" type="text/css" href="assets/css/todos.css">
	
	<script type="text/javascript" src="assets/js/lib/jQuery-3.4.1.min.js"></script>
</head>

<?php
  
  session_start();

  if($_SESSION['sentitype'] == "positive")
  {
  	echo "Positive senti score results on :";
  	echo "<br>";
  }
  else
  {
  	echo "Negative senti score results on :";
  	echo "<br>";
  }

  echo "Country :";
  echo $_SESSION['country']; 
  echo "<br>";

  echo "Category :";
  echo $_SESSION['category'];
  echo "<br>";

  echo "Price :";
  echo $_SESSION['price'];
  echo "<br>";
  
?> 

<body>

	<h4><a href ="/appStoreAnalysis_r2/home.php">Home</a></h4>
	<h4><a href ="/appStoreAnalysis_r2/appRecommend/home.php">Back to category</a></h4>
	<p class="mb-5"></p>
	
	<div class="container ">


      <div class="row border">
	  <div class="col-sm-6 col-md-4 bg-white">
	  		<h1>Apps link recommended for you on Google store</h1>
			<ul class="first"></ul>
	  </div>
  	<div class="col-md-4 bg-red"></div>
  	<div class="col-sm-6 col-md-4 bg-dark">
  		<h1>Apps link recommended for you on Apple store</h1>
		
			<ul class="second"></ul>
  	</div>


</div>

</div>

<script type="text/javascript" src="assets/js/todos.js"></script>
</body>
</html>




