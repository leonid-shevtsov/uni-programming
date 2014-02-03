<?php

class UsersDB extends SQLite3
{
    function __construct()
    {
        $this->open('lab6.sqlite3');
        $this->exec('CREATE TABLE IF NOT EXISTS users (name VARCHAR NOT NULL, password_hash VARCHAR NOT NULL)');
    }

    function checkUser($name, $password)
    {
      $stmt = $this->prepare("SELECT * FROM users WHERE name=:name AND password_hash=:password_hash");
      $stmt->bindValue(':name', $name);
      $stmt->bindValue(':password_hash', $this->hashPassword($password));
      $res = $stmt->execute();
      return !!$res->fetchArray();
    }

    function userExists($name)
    {
      $stmt = $this->prepare("SELECT * FROM users WHERE name=:name");
      $stmt->bindValue(':name', $name);
      $res = $stmt->execute();
      return !!$res->fetchArray();
    }

    function signup($name, $password)
    {
      if ($this->userExists($name)) {
        throw new Exception('User already exists');
      } else if ($name=='' || $password=='') {
        throw new Exception('Name and password are required');
      } else {
        $stmt = $this->prepare('INSERT INTO users (name, password_hash) VALUES (:name, :password_hash)');
        $stmt->bindValue(':name', $name);
        $stmt->bindValue(':password_hash', $this->hashPassword($password));
        $stmt->execute();
      }
    }

    function hashPassword($password)
    {
      return sha1('SECURESALT'.$password);
    }
}

$db = new UsersDB();
