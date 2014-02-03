<?php
  require 'lab6_init.php';

?><!DOCTYPE html>
<html>
  <head>
    <meta charset="utf8">
    <title>Authorisation example</title>
  </head>
  <body>
    <?php if ($currentUser) { ?>
      <p>Hello, <?php echo $currentUser ?></p>
      <p><a href="lab6_logout.php">Logout</a></p>
    <?php } else { ?>
      <form method="post" action="lab6_login.php">
        <h2>Login</h2>
        <label>Name</label>
        <input type="text" name="name">
        <br>
        <label>Password</label>
        <input type="password" name="password">
        <br>
        <input type="submit" value="Login">
      </form>
      <form method="post" action="lab6_signup.php">
        <h2>Signup</h2>
        <label>Name</label>
        <input type="text" name="name">
        <br>
        <label>Password</label>
        <input type="password" name="password">
        <br>
        <input type="submit" value="Signup">
      </form>
    <?php } ?>
  </body>
</html>