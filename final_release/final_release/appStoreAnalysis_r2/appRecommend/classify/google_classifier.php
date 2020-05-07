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

  $id = $_GET["id"];
  //$name = $_GET["name"]
  $_SESSION["appId"] = $id;
  //$_SESSION["appName"] = $name;
  $cmd1 = "google.exe"." ".$id;
  $cmd2 = "python google_classifier.py";

  exec($cmd1." && ".$cmd2);
  
  header('Location: google_display.php');
  
?>

</body>
</html>