<?php

/**
 * @file
 * Entity property info file.
 */

/**
 * Implements hook_entity_property_info().
 */
function dir_entity_property_info() {
  $info = array();
  // Add 'roles' property to dir_link.
  $roles_property_info = dir_link_roles_entity_property_info();
  $info['dir_link']['properties']['roles'] = array(
    'label' => t('Roles of link'),
    'descriptoin' => t('List of roles this link has.'),
    'type' => 'struct',
    'computed' => TRUE,
    'getter callback' => 'dir_link_roles_entity_property_getter',
    'property info' => $roles_property_info,
  );
  // Add 'parent'/'child' property to dir_container category.
  $info['dir_container']['bundles']['category']['properties']['parent'] = array(
    'label' => t('Parent category'),
    'descriptoin' => t('List of parent categories.'),
    'type' => 'list<dir_container>',
    'computed' => TRUE,
    'getter callback' => 'dir_container_parent_entity_property_getter',
  );
  $info['dir_container']['bundles']['category']['properties']['child'] = array(
    'label' => t('Child category'),
    'descriptoin' => t('List of child categories.'),
    'type' => 'list<dir_container>',
    'computed' => TRUE,
    'getter callback' => 'dir_container_child_entity_property_getter',
  );

  return $info;
}
