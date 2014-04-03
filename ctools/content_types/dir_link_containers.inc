<?php

/**
 * @file
 * CTools content_types plugin: dir_link_containers.
 */

$plugin = array(
	'title' => t('Link containers'),
  'description' => t('Display link containers.'),
  'category' => 'Dir',
  'required context' => new ctools_context_required(t('Dir: Link'), 'dir_link'),
);

function dir_dir_link_containers_content_type_render($subtype, $conf, $args, $pane_context, $incoming_content) {
  $link = $pane_context->data;
  $link_wrapper = entity_metadata_wrapper('dir_link', $link);
  $cons = $link_wrapper->containers;
  $entity_info = entity_get_info('dir_container');
  $content = '';

  foreach ($cons as $con_type => $con_list) {
    $containers = array();
    if ($con_list->count()) {
      foreach ($con_list as $con_wrapper) {
        $con = $con_wrapper->value();
        $containers[] = l($con->title, 'dir/container/' . $con->id);
      }
    }
    $content .= theme('item_list', array('title' => $entity_info['bundles'][$con_type]['label'], 'items' => $containers));
  }

  $block = new stdClass();
  $block->title = t('Containers');
  $block->content = $content;

  return $block;
}
