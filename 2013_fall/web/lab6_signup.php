<?php
  require 'lab6_init.php';
  if (!$currentUser) {
    $name = $_POST['name'];
    $password = $_POST['password'];
    try {
      $db->signup($name, $password);
    } catch (Exception $e) {
      echo $e->getMessage();
      die;
    }
    $_SESSION['currentUser'] = $name;
  }
  header("Location: lab6.php");
