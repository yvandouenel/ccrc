<?php
/**
 * @file
 * intranet.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function intranet_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function intranet_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function intranet_node_info() {
  $items = array(
    'informations_internes' => array(
      'name' => t('Informations internes'),
      'base' => 'node_content',
      'description' => t('Textes, documents, brèves destinées à l\'interne (élus, salariés de la CC) '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
