<!DOCTYPE HTML>  
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body> 

<?php
// define variables and set to empty values
  session_start();
?>

<h4><a href ="/appStoreAnalysis_r2/home.php">Home</a></h4>
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

<h2> Input app name </h2>
<input type="text" name="name">
  <br><br>

<input type="submit" name="submit1" value="OK">
</form>

<?php

  function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }

  if(isset($_POST['submit1'])){
    $country = $_POST['country']; 
    $name = test_input($_POST['name']);
    echo "<br>";
    
    if(empty($name))
    {
      echo "Valid Name required : Only alphanumeric";
    }
    else
    {
      echo $country;
      echo "<br>";
      echo $name;
      echo "<br>";

      $cmd1 = 'node google_search.js'.' '.$country.' '.$name.' '.'> input.txt';
      echo $cmd1;
      echo "<br>";

      $cmd2 = 'node apple_search.js'.' '.$country.' '.$name.' '.'> input_2.txt';
      echo $cmd2;
      echo "<br>";

      $cmd3 = 'single_app_detail.exe';
      echo $cmd3;
      echo "<br>";

      $cmd4 = 'single_app_detail_2.exe';
      echo $cmd4;
      exec($cmd1."; ".$cmd2."; ".$cmd3."; ".$cmd4);
      echo "<br>";

      header('Location: display.html');
    }
  }
?>

</body>
</html>