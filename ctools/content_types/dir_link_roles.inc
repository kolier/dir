<?php

/**
 * @file
 * CTools content_types plugin: dir_link_roles.
 */

$plugin = array(
  'title' => t('Link roles'),
  'description' => t('Display link roles.'),
  'category' => 'Dir',
  'required context' => new ctools_context_required(t('Dir: Link'), 'dir_link'),
);

function dir_dir_link_roles_content_type_render($subtype, $conf, $args, $pane_context, $incoming_content) {
  $link = $pane_context->data;
  $link_wrapper = entity_metadata_wrapper('dir_link', $link);
  $entity_info = entity_get_info('dir_role');
  $roles = array();
  $role_list = $link_wrapper->role->value();
  if ($role_list) {
    foreach ($link_wrapper->role->value() as $role) {
      $roles[] = l($entity_info['bundles'][$role->type]['label'], 'dir/link/' . $link->id . '/' . $role->type);
    }
  }

  $block = new stdClass();
  $block->title = t('Roles');
  $block->content = theme('item_list', array('items' => $roles));

  return $block;
}
