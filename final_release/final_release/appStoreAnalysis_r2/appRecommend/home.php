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
  $_SESSION['category'] ="edu";
?> 

<h4><a href ="/appStoreAnalysis_r2/home.php">Home</a></h4>
<h2> Choose a category </h2><br><br>
<form method="post" action="filter.php">
  <table>
  <tr><td><input type="submit" name="edu" value="EDUCATION"></td>
  <td><input type="submit" name="ent" value="ENTERTAINMENT"></td></tr>
  <tr><td><input type="submit" name="foo" value="FOOD AND DRINK"></td>
  <td><input type="submit" name="lif" value="LIFESTYLE"></td></tr>
  <tr><td><input type="submit" name="map" value="MAPS AND NAVIGATION"></td>
  <td><input type="submit" name="mus" value="MUSIC"></td></tr>
  <tr><td><input type="submit" name="new" value="NEWS"></td>
  <td><input type="submit" name="pho" value="PHOTOGRAPHY"></td></tr>
  <tr><td><input type="submit" name="pro" value="PRODUCTIVITY"></td>
  <td><input type="submit" name="sho" value="SHOPPING"></td></tr>
  <tr><td><input type="submit" name="soc" value="SOCIAL"></td>
  <td><input type="submit" name="too" value="TOOLS"></td></tr>
  <tr><td><input type="submit" name="tra" value="TRAVEL"></td>
  <td><input type="submit" name="gam" value="GAME"></td></tr>
</table>
</form>

</body>
</html>