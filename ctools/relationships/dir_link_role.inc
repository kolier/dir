<?php

/**
 * @file
 * ctools relationships plugin: dir_link_role.
 */

$plugin = array(
  'title' => t('Link role'),
  'description' => t('Get role context by link.'),
  'keyword' => 'dir_role',
  'required context' => new ctools_context_required(t('Dir: Link'), 'dir_link'),
  'context' => 'dir_dir_link_role_context',
  'edit form' => 'dir_dir_link_role_edit_form',
  'defaults' => array('type' => 'website'),
);

/**
 * Return a new context based on an existing context.
*/
function dir_dir_link_role_context($context, $conf) {

  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    return ctools_context_create_empty('entity:dir_role', NULL);
  }

  $link_wrapper = entity_metadata_wrapper('dir_link', $context->data);
  $role = $link_wrapper->roles->{$conf['type']}->value();
  if ($role) {
    return ctools_context_create('entity:dir_role', $role);
  }

  return FALSE;
}

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
