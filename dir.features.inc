<?php
/**
 * @file
 * dir.features.inc
 */

/**
 * Implements hook_eck_entity_type_info().
 */
function dir_eck_entity_type_info() {
  $items = array(
    'dir_container' => array(
      'name' => 'dir_container',
      'label' => 'Dir: Container',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
    'dir_link' => array(
      'name' => 'dir_link',
      'label' => 'Dir: Link',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'url' => array(
          'label' => 'URL',
          'type' => 'url',
          'behavior' => 'url',
        ),
      ),
    ),
    'dir_role' => array(
      'name' => 'dir_role',
      'label' => 'Dir: Role',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'link_id' => array(
          'label' => 'Link',
          'type' => 'positive_integer',
          'behavior' => 'entityreference',
        ),
        'summary' => array(
          'label' => 'Summary',
          'type' => 'longtext',
          'behavior' => 'textarea',
        ),
      ),
    ),
  );
  return $items;
}
