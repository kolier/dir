<?php

/**
 * @file
 * ctools relationships plugin: dir_link_role.
 */

$plugin = array(
  'title' => t('Dir: Role'),
  'description' => t('Get role context by link.'),
  'keyword' => 'dir_role',
  'required context' => array(
      new ctools_context_required(t('Dir: Link'), 'dir_link'),
      new ctools_context_required(t('Role type'), 'string'),
  ),
  'context' => 'dir_dir_link_role_context',
);

/**
 * Return a new context based on an existing context.
*/
function dir_dir_link_role_context($contexts, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($contexts[0]->data)) {
    return ctools_context_create_empty('entity:dir_role', NULL);
  }

  if (KtoolsEntity::bundleExists('dir_role', $contexts[1]->data)) {
    $link_wrapper = entity_metadata_wrapper('dir_link', $contexts[0]->data);
    $role = $link_wrapper->roles->{$contexts[1]->data}->value();
    if ($role) {
      return ctools_context_create('entity:dir_role', $role);
    }
  }

  return FALSE;
}
