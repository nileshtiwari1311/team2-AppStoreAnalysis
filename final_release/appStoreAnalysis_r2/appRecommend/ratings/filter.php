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

<h2> Choose rating </h2>
  <input type="radio" id="all" name="rating" value="0" checked>
  <label for="all">Overall</label><br>
  <input type="radio" id="recent" name="rating" value="1">
  <label for="recent">Recent</label><br>

<h2> Choose score </h2>
  <select id="score" name="score">
    <option value="0">0+</option>
    <option value="1">1+</option>
    <option value="2">2+</option>
    <option value="3">3+</option>
    <option value="4">4+</option>
  </select>

  <br><br>
  <input type="submit" name="submit" value="OK">
</form>

<?php
  if(isset($_POST['submit']))
  {
    $category =  $_SESSION['category'];
    $country = $_SESSION['country']; 
    $price = $_SESSION['price'];

    $score = $_POST['score'];
    $rating = $_POST['rating'];

    $_SESSION['rating'] = $rating;
    echo "<br>";
    echo $category;
    echo "<br>";
    echo $country;
    echo "<br>";
    echo $rating;
    echo "<br>";
    echo $score;
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
    exec($cmd1." && ".$cmd2." && ".$cmd3." && ".$cmd4); 
    echo "<br>";

    header('Location: display.php');

  }
?>

</body>
</html>