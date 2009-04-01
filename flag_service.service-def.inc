<?php
// $Id$

/**
 * Implementation of hook_service().
 */
function _flag_service_service() {
  return array(
    array(
      '#method'           => 'flag.flag',
      '#callback'         => 'flag',
      '#access callback'  => 'flag_service_flag_access',
      '#args'             => array(
        array(
          '#name'           => 'action',
          '#type'           => 'string',
          '#description'    => t('Whether to flag or unflag.')),
        array(
          '#name'           => 'flag_name',
          '#type'           => 'string',
          '#description'    => t('The flag to set or unset.')),
        array(
          '#name'           => 'content_id',
          '#type'           => 'int',
          '#description'    => t('The id of the content to flag.')),
      ),
      '#return'           => 'bool',
      '#help'             => t('Flags or unflags content.')
    ),
    array(
      '#method'           => 'flag.flags',
      '#file'             => array('file' => 'inc', 'module' => 'flag_service'),
      '#callback'         => 'flag_service_get_flags',
      '#access callback'  => 'user_access',
      '#access arguments' => array('access content'),
      '#args'             => array(
        array(
          '#name'           => 'content_type',
          '#optional'       => TRUE,
          '#type'           => 'string',
          '#description'    => t('The content type, node, comment and so on.')),
        array(
          '#name'           => 'content_subtype',
          '#optional'       => TRUE,
          '#type'           => 'string',
          '#description'    => t('The content subtype usually the node content type.')),
      ),
      '#return'           => 'bool',
      '#help'             => t('Get the avaliable flags to set or unset for a content type.')
    ),
    array(
      '#method'           => 'flag.get',
      '#file'             => array('file' => 'inc', 'module' => 'flag_service'),
      '#callback'         => 'flag_service_get_content_flags',
      '#access callback'  => 'user_access',
      '#access arguments' => array('access content'),
      '#args'             => array(
        array(
          '#name'           => 'content_type',
          '#type'           => 'string',
          '#description'    => t('The content type, node, comment and so on.')),
        array(
          '#name'           => 'content_id',
          '#type'           => 'int',
          '#description'    => t('The id of the content to get the flags for.')),
      ),
      '#return'           => 'bool',
      '#help'             => t('Get the flags for a content item.')
    ),
  );
}