<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO"
        crossorigin="anonymous">
  <title>Reviews</title>
  <link rel="stylesheet" type="text/css" href="assets/css/todos.css">
  
  <script type="text/javascript" src="assets/js/lib/jQuery-3.4.1.min.js"></script>
</head>

<?php
  
  session_start();
  echo "Appid : ";
  echo $_SESSION["appId"];
  echo "<br>";
?> 

<body>

  
  <div class="container ">
      <div class="row border">
    <div class="col-sm-6 col-md-4 bg-white">
        <h1>Reviews for app on Apple store</h1>
      <ul class="first"></ul>
    </div>

</div>

</div>

<script type="text/javascript" src="assets/js/apple_todos.js"></script>
</body>
</html>
