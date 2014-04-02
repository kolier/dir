<?php
/**
 * @file
 * dir.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dir_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_dir_category_parent'
  $field_bases['field_dir_category_parent'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dir_category_parent',
    'foreign keys' => array(
      'eck_dir_container' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'eck_dir_container',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'category' => 'category',
        ),
      ),
      'target_type' => 'dir_container',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_dir_container'
  $field_bases['field_dir_container'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dir_container',
    'foreign keys' => array(
      'eck_dir_container' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'eck_dir_container',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'dir_container',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
