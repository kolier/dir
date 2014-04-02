<?php
/**
 * @file
 * dir.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dir_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dir_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function dir_eck_bundle_info() {
  $items = array(
    'dir_container_category' => array(
      'machine_name' => 'dir_container_category',
      'entity_type' => 'dir_container',
      'name' => 'category',
      'label' => 'Category',
    ),
    'dir_link_url' => array(
      'machine_name' => 'dir_link_url',
      'entity_type' => 'dir_link',
      'name' => 'url',
      'label' => 'URL',
    ),
  );
  return $items;
}

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
        'name' => array(
          'label' => 'Name',
          'type' => 'text',
          'behavior' => 'name',
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
        'link' => array(
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
