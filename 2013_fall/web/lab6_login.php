<?php
  require 'lab6_init.php';
  if (!$currentUser) {
    $name = $_POST['name'];
    $password = $_POST['password'];
    if ($db->checkUser($name, $password)) {
      $_SESSION['currentUser'] = $name;
    } else {
      echo 'Incorrect username or password';
      die;
    }
  }
  header("Location: lab6.php");

