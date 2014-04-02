<?php

/**
 * @file
 * CTools content_types plugin: dir_container_links.
 */

$plugin = array(
  'title' => t('Container links'),
  'description' => t('Display links of current container.'),
  'category' => 'Dir',
  'required context' => new ctools_context_required(t('Dir: Container'), 'dir_container'),
);

function dir_dir_container_links_content_type_render($subtype, $conf, $args, $pane_context, $incoming_content) {
  $container = $pane_context->data;

  $container_wrapper = entity_metadata_wrapper('dir_container', $container);
  $links = array();
  foreach ($container_wrapper->links->value() as $link) {
    $links[] = l($link->title . ' (' . $link->url . ')', 'dir/link/' . $link->id);
  }

  $block = new stdClass();
  $block->title = t('Links');
  $block->content = theme('item_list', array('items' => $links));

  return $block;
}
