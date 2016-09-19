<?php

/**
 * @file
 * Select Drupal content to create a newsletter
 */

/**
 * Theme the node selection form
 *
 * @param $form Array The form structure ready to be rendered
 */
function theme_scs_sortable_table($form) {
  $form = $form['form'];
  $headers = array(t('Node title'), t('Weight'));
  $rows = array();

  $nids = element_children($form['nodes']);

  // Fetch the titles for each nid
  $titles = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('nid', array_values($nids))
    ->execute()
    ->fetchAllKeyed();

  foreach ($nids as $nid) {
    $row = array();
    $row[] = $titles[$nid];
    $row[] = drupal_render($form['nodes'][$nid]['weight']);
    $rows[] = array(
      'data' => $row,
      'class' => array('draggable'),
    );
  }
  $output = theme('table', array('header' => $headers, 'rows' => $rows, 'attributes' => array('id' => 'scs-sort-nodes')));
  $info = '';
  if (isset($form['scs_title']) && isset($form['scs_toc'])) {
    $info = drupal_render($form['scs_title']) . drupal_render($form['scs_toc']);
  }
  $output = $info . $output . drupal_render_children($form);
  drupal_add_tabledrag('scs-sort-nodes', 'order', 'sibling', 'node-weight');
  return $output;
}

/**
 * Each selected node goes through this function to create a part of the
 * newsletter body
 *
 * @param $node Array The node, as an array (WTF???)
 */
function theme_scs_node_output($node) {
  $output = '<div id="node_' . $node['nid'] . '">';
  $output .= '<h1>' . $node['title'] . '</h1>';
  $output .= '<p>' . $node['body'][LANGUAGE_NONE][0]['value'] . '</p>';
  $output .= '<p>' . l(t('Read more'), 'node/' . $node['nid']) . '</p>';
  $output .= '</div>';

  return $output;
}

/**
 * Theme function to add the titles of the selected nodes at top of the
 * newsletter to build the table of contents
 *
 * @param $variables Array An array containing 'titles'
 */
function theme_scs_node_titles($variables) {
  if (variable_get('scs_format', 'plain') == 'plain') {
    return implode("\n", $variables['titles']);
  }
  else {
    return '<div id="toc">' . theme('item_list', array('items' => $variables['titles'])) . '</div>';
  }
}

/**
 * Theme a complete newsletter, appending each node rendered through
 * theme_scs_node_output() and appending ToC if required
 *
 * @param $variables Array An array containing 'nodes' and 'toc'
 */
function theme_scs_newsletter_output($variables) {
  $body = '';
  $titles = array();

  // Node information
  foreach ($variables['nodes'] as $node) {
    if ($variables['toc']) {
      if (variable_get('scs_format', 'plain') == 'plain') {
        $titles[] = $node->title;
      }
      else {
        $titles[] = '<a href="#node_' . $node->nid . '">' . $node->title . '</a>';
      }
    }

    $body .= theme('scs_node_output', (array) $node);
  }

  // ToC (if required)
  if ($variables['toc']) {
    $body = theme('scs_node_titles', array('titles' => $titles)) . $body;
  }

  // Complete newsletter body
  return $body;
}
