<?php
/**
 * @file
 * intranet.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function intranet_user_default_roles() {
  $roles = array();

  // Exported role: elu.
  $roles['elu'] = array(
    'name' => 'elu',
    'weight' => 2,
    'machine_name' => 'elu',
  );

  return $roles;
}
