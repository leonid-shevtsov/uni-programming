<?php
  session_start();
  $currentUser = array_key_exists('currentUser', $_SESSION) ? $_SESSION['currentUser'] : null;
  require 'lab6_db.php';