<?php

/**
 * @file
 * CTools content_types plugin: dir_container_category_children.
 */

$plugin = array(
  'title' => t('Category children'),
  'description' => t('Display children of current category.'),
  'category' => 'Dir',
  'required context' => new ctools_context_required(t('Dir: Container'), 'dir_container'),
);

function dir_dir_container_category_children_content_type_render($subtype, $conf, $args, $pane_context, $incoming_content) {
  $category = $pane_context->data;
  $category_wrapper = entity_metadata_wrapper('dir_container', $category);
  $children = array();
  foreach ($category_wrapper->child->value() as $child) {
    $children[] = l($child->title, 'dir/container/' . $child->id);
  }

  $block = new stdClass();
  $block->title = t('Children');
  $block->content = theme('item_list', array('items' => $children));

  return $block;
}
