$(document).ready(function(){
	var resourcesUrl = 'resources.xml';
	
	getResources(resourcesUrl);
});

/**
 * Get resources from URL.
 * 
 * @param string resourcesUrl String containing URL to the resources list
 */
function getResources(resourcesUrl) {
	$.ajax({
		url: resourcesUrl,
		dataType: 'xml',
		type: 'get',
		error: onGetResourcesError,
		success: onGetResourcesSuccess
	});
}

/**
 * getResources error handler
 *  
 * @see getResources
 */
function onGetResourcesError(jqXHR, textStatus, errorThrown) {
	alert(textStatus);
}

/**
 * getResources success handler
 * 
 * Creates markup to show resources list
 * 
 * @see getResources
 */
function onGetResourcesSuccess(data, textStatus, jqXHR) {
	var $list = $('#resources-list');
	var $data = $(data);
	var $resources = $data.find('resource');
	
	if ($resources.size() > 0) {
		$resources.each(function(){
			var $item = $(this);
			var id = $item.attr('href').split('/').pop();
			
			var $listItem = $('<dt>')
				.attr('id', 'resource-' + id)
				.attr('data-toggle', 'collapse')
				.attr('data-target', '#resource-' + id + ' + dd')
				.text($item.find('name').text()).
				on('click', toggleToggleIcon);
				
			var $icon = $('<i>')
				.addClass('icon-plus-sign')
			$icon.prependTo($listItem);
			
			var $attrs = $item.find('attribute');
			if ($attrs.size() > 0) {
				$listItem.appendTo($list);
				
				var $descr = $('<dd>').addClass('collapse');
				var $ul = $('<ul>');
				$attrs.each(function(){
					var $item = $(this);
					var $li = $('<li>');
					$li.text($item.attr('name') + ': ' + $item.attr('value'));
					$li.appendTo($ul);
				});
				$ul.appendTo($descr);
				$descr.appendTo($list);
			}
		});
		
		$list.parents('div').removeClass('collapse');
	}
}

/**
 * Toggles 'toggle' icon
 * 
 * @see onGetResourcesSuccess
 */
function toggleToggleIcon() {
	$icon = $(this).find('i[class^=icon]');

	// do action if only one icon found (can be changed to .each loop instead)
	// and it is either icon-plus-sign or icon-minus-sign
	if (
		$icon.size() == 1 && 
		$icon.is('.icon-plus-sign, .icon-minus-sign')
	) {
		$icon.toggleClass('icon-plus-sign icon-minus-sign');
	}
}
