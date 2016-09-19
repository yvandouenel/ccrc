<?php
/**
 * @file
 * feature_display_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_display_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_display_news_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_display_news_image_default_styles() {
  $styles = array();

  // Exported image style: actu_home.
  $styles['actu_home'] = array(
    'name' => 'actu_home',
    'effects' => array(
      1 => array(
        'label' => 'Mise à l’échelle et recadrage',
        'help' => 'La mise à l\'échelle et le recadrage maintiendront les proportions originales de l\'image puis recadreront la dimension la plus large. C\'est très utile pour créer des vignettes carrées sans étirer les images.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '289',
          'height' => '160',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
