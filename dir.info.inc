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
  // Add 'role' property to dir_link.
  $info['dir_link']['properties']['role'] = array(
    'label' => t('Role'),
    'descriptoin' => t('List of roles of the link.'),
    'type' => 'list<dir_role>',
    'computed' => TRUE,
    'getter callback' => 'dir_link_role_entity_property_getter',
  );
  // Add 'roles' property to dir_link.
  $info['dir_link']['properties']['roles'] = array(
    'label' => t('Roles'),
    'descriptoin' => t('List of roles of the link by types.'),
    'type' => 'struct',
    'property info' => dir_link_roles_entity_property_info(),
    'computed' => TRUE,
    'getter callback' => 'dir_link_roles_entity_property_getter',
  );
  // Add 'containers' property to dir_link.
  $info['dir_link']['properties']['container'] = array(
    'label' => t('Container'),
    'description' => t('List of containers of the link.'),
    'type' => 'list<dir_container>',
    'computed' => TRUE,
    'getter callback' => 'dir_link_container_entity_property_getter',
  );
  // Add 'containers' property to dir_link.
  $info['dir_link']['properties']['containers'] = array(
  	'label' => t('Containers'),
    'description' => t('List of containers of the link by types.'),
    'type' => 'struct',
    'property info' => dir_link_containers_entity_property_info(),
    'computed' => TRUE,
    'getter callback' => 'dir_link_containers_entity_property_getter',
  );
  // Add 'links' property to dir_container.
  $info['dir_container']['properties']['links'] = array(
    'label' => t('Links'),
    'descriptoin' => t('List of links in the container.'),
    'type' => 'list<dir_link>',
    'computed' => TRUE,
    'getter callback' => 'dir_container_links_entity_property_getter',
  );
  // Add 'parent'/'child' property to dir_container category.
  $info['dir_container']['bundles']['category']['properties']['parent'] = array(
    'label' => t('Parent category'),
    'descriptoin' => t('List of parent categories.'),
    'type' => 'list<dir_container>',
    'computed' => TRUE,
    'getter callback' => 'dir_container_category_parent_entity_property_getter',
  );
  $info['dir_container']['bundles']['category']['properties']['child'] = array(
    'label' => t('Child category'),
    'descriptoin' => t('List of child categories.'),
    'type' => 'list<dir_container>',
    'computed' => TRUE,
    'getter callback' => 'dir_container_category_child_entity_property_getter',
  );

  return $info;
}

/**
 * Helper function to generate the roles property info for dir_link.
 */
function dir_link_roles_entity_property_info() {
  $info = array();
  $entity_info = entity_get_info('dir_role');
  foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
    $info[$bundle] = array(
      'label' => $bundle_info['label'],
      'description' => t('@role is a role of link.', array('@role' => $bundle_info['label'])),
      'type' => 'dir_role',
    );
  }

  return $info;
}

/**
 * Helper function to generate the containers property info for dir_link.
 */
function dir_link_containers_entity_property_info() {
  $info = array();
  $entity_info = entity_get_info('dir_container');
  foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
    $info[$bundle] = array(
      'label' => $bundle_info['label'],
      'description' => t('List of @container that include the link.', array('@container' => $bundle_info['label'])),
      'type' => 'list<dir_container>',
    );
  }

  return $info;
}
