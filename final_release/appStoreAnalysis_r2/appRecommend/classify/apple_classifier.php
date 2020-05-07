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
  $cmd1 = "apple.exe"." ".$id;
  $cmd2 = "python apple_classifier.py";

  exec($cmd1." && ".$cmd2);
  
  header('Location: apple_display.php');
  
?>

</body>
</html>