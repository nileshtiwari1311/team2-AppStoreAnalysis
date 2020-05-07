<!DOCTYPE HTML>  
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body>

<?php
  
  session_start();
?> 

<h4><a href ="/appStoreAnalysis_r2/home.php">Home</a></h4>
<h4><a href ="/appStoreAnalysis_r2/appRecommend/home.php">Back to category</a></h4>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">

<h2> Choose type of score </h2>
  <select id="sentitype" name="sentitype">
    <option value="positive">Positive</option>
    <option value="negative">Negative</option>
  </select>

  <br><br>
  <input type="submit" name="submit" value="OK">
</form>

<?php

    set_time_limit(500);
    
  if(isset($_POST['submit'])){
    $category =  $_SESSION['category'];
    $country = $_SESSION['country']; 
    $price = $_SESSION['price'];
    $sentitype = $_POST['sentitype'];
    $_SESSION['sentitype'] = $sentitype;
    $score = "0";
    $rating = "0";
    echo "<br>";
    echo $category;
    echo "<br>";
    echo $country;
    echo "<br>";
    echo $price;
    echo "<br>";

    $cmd1 = 'node scrape.js'.' '.$country.' '.$category.' '.$price.' '.'> test.txt';
    echo $cmd1;
    echo "<br>";

    $cmd2 = 'node scrape_2.js'.' '.$country.' '.$category.' '.$price.' '.'> test_2.txt';
    echo $cmd2;
    echo "<br>";

    $cmd3 = 'param_to_app.exe'.' '.$score.' '.$price.' '.$rating;
    echo $cmd3; 
    echo "<br>";

    $cmd4 = 'param_to_app_2.exe'.' '.$score.' '.$price.' '.$rating;
    echo $cmd4; 
    echo "<br>";

    $cmd5 = 'google_play_store_reviews.exe'.' '.$sentitype;
    echo $cmd5;
    echo "<br>";

    $cmd6 = 'apple_app_store_reviews.exe'.' '.$sentitype;
    echo $cmd6;
    exec($cmd1." && ".$cmd2." && ".$cmd3." && ".$cmd4." && ".$cmd5." && ".$cmd6);
    echo "<br>";

    header('Location: display.php');

  }
?>

</body>
</html>