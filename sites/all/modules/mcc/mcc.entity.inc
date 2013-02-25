<?php
/**
 * @file
 * Entity API hooks for mcc module.
 */

/**
 * Implements hook_entity_info().
 */
function mcc_entity_info() {
  $return = array(
    'mcc' => array(
      'label' => t('MailChimp Campaigns'),
      'controller class' => 'EntityAPIController',
      'base table' => 'mcc_node_campaigns',
      'uri callback' => 'mcc_uri',
      'fieldable' => FALSE,
      'entity keys' => array(
        'id' => 'cid',
      ),
    ),
  );
  return $return;
}

/**
 * Saves a campaign.
 */
function mcc_save($campaign) {
  return entity_get_controller('mcc')->save($campaign);
}

/**
 * Load a campaign by ID.
 */
function mcc_load($cid) {
  $campaign = mcc_load_multiple(array($cid));
  return $campaign ? $campaign[$cid] : FALSE;
}

/**
 * Loads multiple campaigns.
 */
function mcc_load_multiple($campaign_ids = array(), $conditions = array(), $reset = FALSE) {
  if (empty($campaign_ids)) {
    $campaign_ids = FALSE;
  }
  return entity_load('mcc', $campaign_ids, $conditions, $reset);
}

/**
 * Loads campaigns attached to specific nodes.
 */
function mcc_load_by_nid($nid, $vid = FALSE) {
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'mcc')
    ->propertyCondition('nid', $nid);

  if ($vid) {
    $entities = $entities->propertyCondition('vid', $vid);
  }

  $entities = $entities->propertyOrderBy('update_time', 'DESC')
    ->execute();

  if ($entities) {
    foreach ($entities['mcc'] as $entity) {
      $campaign_ids[] = $entity->cid;
    }
    return mcc_load_multiple($campaign_ids);
  }
  else {
    return FALSE;
  }
}

/**
 * Delete a campaign.
 */
function mcc_delete($cid) {
  return mcc_delete_multiple(array($cid));
}

/**
 * Delete multiple campaigns.
 */
function mcc_delete_multiple($campaign_ids) {
  return entity_get_controller('mcc')->delete($campaign_ids);
}
