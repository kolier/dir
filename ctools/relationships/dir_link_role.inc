<?php

/**
 * @file
 * ctools relationships plugin: dir_link_role.
 */

$plugin = array(
<<<<<<< HEAD
  'title' => t('Dir: Role'),
  'description' => t('Get role context by link.'),
  'keyword' => 'dir_role',
  'required context' => array(
      new ctools_context_required(t('Dir: Link'), 'dir_link'),
      new ctools_context_required(t('Role type'), 'string'),
  ),
  'context' => 'dir_dir_link_role_context',
=======
  'title' => t('Link role'),
  'description' => t('Get role context by link.'),
  'keyword' => 'dir_role',
  'required context' => new ctools_context_required(t('Dir: Link'), 'dir_link'),
  'context' => 'dir_dir_link_role_context',
  'edit form' => 'dir_dir_link_role_edit_form',
  'defaults' => array('type' => 'website'),
>>>>>>> c70d801eb70a8d4d1166ae043e03644d94485275
);

/**
 * Return a new context based on an existing context.
*/
<<<<<<< HEAD
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
=======
function dir_dir_link_role_context($context, $conf) {

  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    return ctools_context_create_empty('entity:dir_role', NULL);
  }

  $link_wrapper = entity_metadata_wrapper('dir_link', $context->data);
  $role = $link_wrapper->roles->{$conf['type']}->value();
  if ($role) {
    return ctools_context_create('entity:dir_role', $role);
>>>>>>> c70d801eb70a8d4d1166ae043e03644d94485275
  }

  return FALSE;
}
<<<<<<< HEAD
=======

/**
 * Settings form.
 */
function dir_dir_link_role_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Link role type'),
    '#options' => KtoolsEntity::bundleOptions('dir_role'),
    '#default_value' => $conf['type'],
  );

  return $form;
}
>>>>>>> c70d801eb70a8d4d1166ae043e03644d94485275
