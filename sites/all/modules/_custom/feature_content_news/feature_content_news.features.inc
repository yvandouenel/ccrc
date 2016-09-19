<?php
/**
 * @file
 * feature_content_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_news_node_info() {
  $items = array(
    'actualites' => array(
      'name' => t('Actualités'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
