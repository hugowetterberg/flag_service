<?php
// $Id$

function flag_service_get_content_flags($content_type, $content_id) {
  $flags = flag_get_content_flags($content_type, $content_id);
  return $flags ? $flags : array();
}

function flag_service_get_flags($content_type=NULL, $content_subtype=NULL) {
  $flags = array();
  foreach (flag_get_flags($content_type, $content_subtype) as $name => $flag) {
    $flags[$name] = (array)$flag;
  }
  return $flags;
}