<?php
  require 'lab6_init.php';
  unset($_SESSION['currentUser']);
  header('Location: lab6.php');