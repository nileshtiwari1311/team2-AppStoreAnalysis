<!DOCTYPE HTML>  
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body>

<h4><a href ="/appStoreAnalysis_r2/home.php">Home</a></h4>
<h4><a href ="/appStoreAnalysis_r2/appRecommend/home.php">Back to category</a></h4>

<?php

    session_start();

    $category =  $_SESSION['category'];
    $country = $_SESSION['country']; 
    $price = $_SESSION['price'];

    echo "<br>";
    echo $category;
    echo "<br>";
    echo $country;
    echo "<br>";
    echo $price;
    echo "<br>";

    $cmd1 = 'google_downloads.exe'.' '.$country.' '.$category.' '.$price;
    echo $cmd1;
    echo "<br>";

    $cmd2 = 'apple_downloads.exe'.' '.$country.' '.$category.' '.$price;
    echo $cmd2;
    exec($cmd1." && ".$cmd2); 
    echo "<br>";

    header('Location: display.php');
?>

</body>
</html>