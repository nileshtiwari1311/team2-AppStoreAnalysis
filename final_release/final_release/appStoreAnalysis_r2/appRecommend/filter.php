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
  if(isset($_POST['edu'])) { 
      $_SESSION['category'] ="edu"; 
  } 
  if(isset($_POST['ent'])) { 
      $_SESSION['category'] ="ent"; 
  } 
  if(isset($_POST['foo'])) { 
      $_SESSION['category'] ="foo"; 
  } 
  if(isset($_POST['lif'])) { 
      $_SESSION['category'] ="lif"; 
  } 
  if(isset($_POST['map'])) { 
      $_SESSION['category'] ="map"; 
  } 
  if(isset($_POST['mus'])) { 
      $_SESSION['category'] ="mus"; 
  } 
  if(isset($_POST['new'])) { 
      $_SESSION['category'] ="new"; 
  } 
  if(isset($_POST['pho'])) { 
      $_SESSION['category'] ="pho"; 
  } 
  if(isset($_POST['pro'])) { 
      $_SESSION['category'] ="pro"; 
  } 
  if(isset($_POST['sho'])) { 
      $_SESSION['category'] ="sho"; 
  } 
  if(isset($_POST['soc'])) { 
      $_SESSION['category'] ="soc"; 
  } 
  if(isset($_POST['too'])) { 
      $_SESSION['category'] ="too"; 
  } 
  if(isset($_POST['tra'])) { 
      $_SESSION['category'] ="tra"; 
  } 
  if(isset($_POST['gam'])) { 
      $_SESSION['category'] ="gam"; 
  } 
?> 

<h4><a href ="/appStoreAnalysis_r2/home.php">Home</a></h4>
<h4><a href ="/appStoreAnalysis_r2/appRecommend/home.php">Back to category</a></h4>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">

<h2> Choose country </h2>
  <select id="country" name="country">
    <option value="ae">United Arab Emirates</option>
    <option value="au">Australia</option>
    <option value="ca">Canada</option>
    <option value="cn">China</option>
    <option value="de">Germany</option>
    <option value="fr">France</option>
    <option value="gb">UK</option>
    <option value="in">India</option>
    <option value="it">Italy</option>
    <option value="jp">Japan</option>
    <option value="ru">Russia</option>
    <option value="sa">Saudi Arabia</option>
    <option value="sg">Singapore</option>
    <option value="us">USA</option>
  </select>

<h2> Choose price </h2>
  <select id="price" name="price">
    <option value="free">Free</option>
    <option value="paid">Paid</option>
  </select>

<h2> Choose metric </h2>
  <select id="metric" name="metric">
    <option value="ratings">Ratings</option>
    <option value="downloads">Downloads</option>
    <option value="sentiscore">Senti score</option>
  </select>

  <br><br>
  <input type="submit" name="submit" value="OK">
</form>

<?php
  if(isset($_POST['submit'])){
    $country = $_POST['country'];
    $_SESSION['country'] = $country;
    $price = $_POST['price'];
    $_SESSION['price'] = $price;
    $category =  $_SESSION['category'];
    $metric = $_POST['metric'];
    $_SESSION['metric'] = $metric;
    echo "<br>";
    echo $category;
    echo "<br>";
    echo $country;
    echo "<br>";
    echo $price;
    echo "<br>";

    if($metric == "ratings")
    {
      header('Location: ratings/filter.php');
    }
    elseif($metric == "downloads")
    {
      header('Location: downloads/filter.php');
    }
    elseif($metric == "sentiscore")
    {
      header('Location: senti/filter.php');
    }

  }
?>

</body>
</html>