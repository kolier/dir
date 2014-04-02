<?php

/**
 * @file
 * CTools content_types plugin:
 */

$plugin = array(
    'title' => t('Category parent'),
    'description' => t('Display parent of current category.'),
    'category' => 'Dir',
    'required context' => new ctools_context_required(t('Dir: Container'), 'dir_container'),
);

function dir_dir_container_category_parent_content_type_render($subtype, $conf, $args, $pane_context, $incoming_content) {
  $category = $pane_context->data;

  $category_wrapper = entity_metadata_wrapper('dir_container', $category);
  $parents = array();
  foreach ($category_wrapper->parent->value() as $parent) {
    $parents[] = l($parent->title, 'dir/container/' . $parent->id);
  }

  $block = new stdClass();
  $block->title = t('Parent');
  $block->content = theme('item_list', array('items' => $parents));

  return $block;
}
