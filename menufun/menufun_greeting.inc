<?php

function menufun_greeting($first_name = 'Jane', $last_name = 'Doe', $from_first_name = 'John', $from_last_name = 'Doe') {
  return t('Hello @first_name @last_name from @from_first_name @from_last_name', array('@first_name' => $first_name, '@last_name' => $last_name, '@from_first_name' =>
    $from_first_name, '@from_last_name' => $from_last_name));
}

function menufun_farewell() {
  return t("G'bye");
}